#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n,m,x,y;
    cin >> n >> m >> x >> y;
    vector<int> nx(n);
    vector<int> ny(m);
    for(int i=0; i<n; i++){
        cin >> nx.at(i);
    }
    for(int i=0; i<m; i++){
        cin >> ny.at(i);
    }
    sort(nx.begin(),nx.end(),greater());
    sort(ny.begin(),ny.end());
    for(int z=x+1; z<=y; z++){
        if(nx.at(0) < z && z <= ny.at(0)){
            cout << "No War" << endl;
            return 0;
        }
    }
    cout << "War" << endl;
}