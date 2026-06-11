#include <bits/stdc++.h>
using namespace std;

int main(){
   
    int N;
    cin>>N;
    vector<pair<string,pair<int,int>>> S(N);
    for(int i=0;i<N;i++){
        string a;
        int b;
        cin>>a>>b;
        S[i].first=a;
        S[i].second.first=-b;
        S[i].second.second=i+1;
    }
    sort(S.begin(),S.end());
    for(int i=0;i<N;i++){
        cout<<S[i].second.second<<endl;;
    }
}
