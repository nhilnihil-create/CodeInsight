#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> d(n);
    vector<int> used(n+1,0);
    map<int,int> m;
    int max_num=0;
    int max_ind=0;
    int vec_ind=0;
    rep(i,n){
        int p;
        cin >> p;
        if(used[p-1]==0){
            m.insert(make_pair(p,vec_ind));
            d[vec_ind].push_back(p);
            used[p]=1;
            if(max_num<d[vec_ind].size()) max_num=d[vec_ind].size();
            vec_ind++;
        }
        else{
            int ind = m.at(p-1);
            d[ind].push_back(p);
            m.insert(make_pair(p,ind));
            if(max_num<d[ind].size()) max_num=d[ind].size();
            used[p]=1;
        }
    }
    /*
    cout <<"vec" << endl;
    rep(i,d.size()){
        for(auto v:d[i]) cout << v << " ";
        cout << endl;
    }
    cout << "maxlen " << max_num << endl; 
    */
    cout << n-max_num << endl;


}