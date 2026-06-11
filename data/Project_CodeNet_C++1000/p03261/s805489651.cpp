#include <bits/stdc++.h>
using namespace std;
typedef long long ll;



int main(){
    ll N;
    cin >> N;
    vector<string> siritori(N,"");
    vector<string> siritori_check;
    for(int i = 0; i < N; i++) cin >> siritori[i];

    siritori_check = siritori;
    sort(siritori_check.begin(),siritori_check.end());
    auto result = unique(siritori_check.begin() , siritori_check.end());
    siritori_check.erase(result, siritori_check.end());


    if(siritori_check.size() != N){
        cout << "No" <<endl;
        return 0;
    }

    for(int i = 0; i < N - 1; i++){
        if(siritori[i][siritori[i].size() - 1] != siritori[i + 1][0]){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;
    return 0;

}
