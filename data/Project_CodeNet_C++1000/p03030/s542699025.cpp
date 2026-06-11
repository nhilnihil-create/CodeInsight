#include <iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;



int main() {
    int n;
    cin>>n;
    vector<tuple<string,int,int>>score(n);
    rep(i,n){
        string s;
        int p;
        cin>>s>>p;
        p = -p;
        score[i] = tie(s,p,i);
    }
    sort(score.begin(),score.end());
    rep(i,n)cout<<get<2>(score[i]) + 1 <<endl;

    return 0;
}
