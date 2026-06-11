#include<iostream>
#include<cmath>
#include<vector>
#include<bitset>
#include<bitset>
#include<string>
#include<utility>
#include<queue>

using namespace std;
long long int gcd(long long int a,long long int b);
int main(){
    int n;
    cin >> n;
    vector<long long int> a(n);
    vector<long long int> gcda(n);
    vector<long long int> gcdb(n);
    
    // vector<long long int> gcdm(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    if(n==2){
        cout << max(a.at(0),a.at(1)) << endl;
        return 0;
    }
    gcda.at(0)=a.at(0);
    for(int i=1;i<n;i++){
        gcda.at(i) = gcd(a.at(i),gcda.at(i-1));
    }
    gcdb.at(n-1)=a.at(n-1);
    for(int i=1;i<n;i++){
        gcdb.at(n-1-i)=gcd(a.at(n-1-i),gcdb.at(n-i));
    }

    long long int ans=max(gcdb.at(1),gcda.at(n-2));
    long long int temp;
    for(int i=1;i<n-1;i++){
        
        temp= gcd(gcda.at(i-1),gcdb.at(i+1));
        // cout << gcda.at(i) <<","<<gcdb.at(i) <<","<<temp << endl;
        if(temp>ans)ans=temp;
    }
    
    cout << ans << endl;
    return 0;
}
long long int gcd(long long int a,long long int b){
    if(a<b)swap(a,b);
    if(a%b==0)return b;
    else return gcd(b,a%b);
}