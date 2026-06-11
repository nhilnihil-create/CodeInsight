#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,p;
    string s;
    cin>>n;
    pair<pair<string,long long>,long long > ss[n];
    f(i,0,n){
        cin>>s>>p;
        ss[i]=make_pair(make_pair(s,-p),i);
    }
    sort(ss,ss+n);
    f(i,0,n){
        cout<<ss[i].second+1<<endl;
    }
    return 0;
}
