#include<bits/stdc++.h>
using namespace std;

static const int MAX=100;

int main(){
    int N; cin >> N;
    vector<int> D;
    D.push_back(0);
    for(int i=0;i<N;i++){
        int d; cin >> d;
        D.push_back(d);
    }
    sort(D.begin(),D.end());
    vector<int> ans;
    ans.push_back(0);
    for(int i=1;i<D.size();i++){
        if(i%2==1) ans.push_back(D[i]);
        else ans.push_back(24-D[i]);
    }
    /*
    for(int i=0;i<ans.size();i++){
        cout << ans[i] << endl;
    }
    */
    sort(ans.begin(),ans.end());
    ans.push_back(24);
    int a=100;
    for(int i=0;i<ans.size()-1;i++){
        a=min(ans[i+1]-ans[i],a);
    }
    cout << a << endl;
}