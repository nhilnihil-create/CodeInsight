#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <string> w(n,"");
    for(int i = 0; i < n; i++){
        cin >> w[i];
        if(i!=0){
            if(w[i-1].back()!=w[i][0]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    sort(w.begin(),w.end());
    for(int i = 1; i < n; i++){
        if(w[i-1].compare(w[i])==0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}