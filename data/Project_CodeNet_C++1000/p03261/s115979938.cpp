#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<string> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    string ans = "Yes";
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(w[j] == w[i]) ans = "No";
        }
        if(*(w[i-1].end()-1) != *(w[i].begin())) ans = "No";
    }
    cout << ans << endl;
    return 0;
}