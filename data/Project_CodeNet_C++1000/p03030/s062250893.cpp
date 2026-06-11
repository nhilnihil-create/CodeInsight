#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<pair<pair<string,int>,int>> book(n);

    rep(i,n){
        string s;
        int p;
        cin>>s>>p;
        book[i].first.first=s;
        book[i].first.second=p*-1;
        book[i].second=i+1;
    }
    sort(book.begin(),book.end());
    rep(i,n) cout<<book[i].second<<"\n";
    return 0;
}