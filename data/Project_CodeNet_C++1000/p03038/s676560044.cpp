#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <string>
#include <utility>
#include <queue>
#include <algorithm>
#include<set>
using namespace std;
long long int mpown(long long int m, int n);
long long int bign=1000000007;
int bitCount(int bits);
int main()
{
    int n,m;
    cin >> n >> m;
    // set<long long int> a;
    vector<long long int> a(n);
    long long int inp;
    for(int i=0;i<n;i++){
        cin >> a.at(i);
        // a.insert(inp)
    }
    sort(a.begin(),a.end());
    pair<long long int,long long int> cb[m];
    long long int b,c;
    for(int i=0;i<m;i++){
        cin >> b >> c;
        cb[i]=make_pair(-c,b);
    }
    sort(cb,cb+m);
    long long int ind=0;
    int nokori=cb[0].second;
    long long int ans=0;
    for(int i=0;i<n;i++){
        if(nokori ==0 || ind>=m){
            ans+= a.at(i);
        }else if(a.at(i) < (-cb[ind].first)){
            ans-=cb[ind].first;
            nokori--;
            if(nokori==0){
                ind++;
                if(ind < m)nokori=cb[ind].second;
            };
        }else{
            ans+= a.at(i);
        }
        
    }
    cout << ans << endl;
    // for(int i=0;i<m;i++){
    //     if(ind+cb[i].second >= n){

    //     }
    //     if(a.at(ind+cb[i].second) >= (-cb[i].first)){
    //         ans = ans+(-cb[i].first)*cb[i].second;
    //     }

    // }

    return 0;
}

int bitCount(int bits)
{
    bits = (bits & 0x55555555) + (bits >> 1 & 0x55555555); //  2bitごとに計算
    bits = (bits & 0x33333333) + (bits >> 2 & 0x33333333); //  4bitごとに計算
    bits = (bits & 0x0f0f0f0f) + (bits >> 4 & 0x0f0f0f0f); //  8bitごとに計算
    bits = (bits & 0x00ff00ff) + (bits >> 8 & 0x00ff00ff); //  16ビットごとに計算
    return (bits & 0x0000ffff) + (bits >> 16);             //  32ビット分を計算
}
long long int mpown(long long int m, int n)
{
    if (n == 0)
        return 1;
    else if (n == 1)
        return m;
    else
    {
        long long int temp = mpown(m, n / 2);
        return temp * temp * (n & 1 ? m : 1);
    }
}