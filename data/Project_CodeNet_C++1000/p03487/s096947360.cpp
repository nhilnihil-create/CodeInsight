#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    map<int,int> kani;
    for(int i=0;i<N;i++){
        int a;
        cin >> a;
        kani[a]++;
    }
    int ans=0;
    for(auto x : kani){
        if(x.first>x.second) ans+=x.second;
        if(x.first<x.second) ans+=x.second-x.first;
    }
    cout << ans << endl;

}