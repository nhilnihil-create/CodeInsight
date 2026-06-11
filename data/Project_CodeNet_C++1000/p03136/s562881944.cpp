#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<int> edge(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>edge[i];
        sum += edge[i];
    }
    for (int i=0; i<n; i++){
            if(edge[i]*2 >= sum){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}