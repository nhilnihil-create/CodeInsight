#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;
    vector <int> a(N);
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }
    if(N == 1 && a[0] == 1){
        cout << 0 << endl;
        return 0;
    }
    if(N == 1 && a[0] != 1){
        cout << 1 << endl;
        return 0;
    }
    sort(a.begin() , a.end());
    a.push_back('a');
    int erase = 0 , much = 1;
    for(int i = 0; i < N; i++){
        if(a[i] == a[i + 1]){
            much++;
        }
        else{
            if(much > a[i]){
                erase += much - a[i];
            }
            else if(much < a[i]){
                erase += much;
            }
            much = 1;
        }
    }
    cout << erase << endl;
}