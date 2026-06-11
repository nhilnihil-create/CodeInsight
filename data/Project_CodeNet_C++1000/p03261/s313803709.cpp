#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    int N;
    cin >> N;
    vector <string> W(N);
    for(int i = 0; i < N; i++){
        cin >> W[i];
    }
    map<string , int> shiritori;
    bool s = true;
    shiritori[W[0]];
    for(int i = 1; i < N; i++){
        if(!(shiritori.count(W[i]))){
            shiritori[W[i]]++;
            string a = W[i - 1];
            string b = W[i];
            if(!(a[a.size() - 1] == b[0])){
                s = false;
            }
        }
        else{
            s = false;
        }
    }
    if(s){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
