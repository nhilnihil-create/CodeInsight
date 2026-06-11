#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
#define vec(j,n) vector<int>(j(n))
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main(){
    int n,d,x;
    cin >> n >> d >> x;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a.at(i);
    }
    int count =0;
    int count1 =0;
    for(int i=0;i<n;i++){
        count1 = (d-1) / a.at(i);
        count += count1;
    }
    cout << count + n + x << endl;
    return 0;
}