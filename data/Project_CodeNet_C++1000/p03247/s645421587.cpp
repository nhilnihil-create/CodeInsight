#include<iostream>
#include<string>
using namespace std;


int N, X[1000], Y[1000];
string ans[1000];
bool is_even;


int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> X[i] >> Y[i];
    }
    for(int i = 0; i < N; i++){
        if(abs(X[0] + Y[0]) % 2 != abs(X[i] + Y[i]) % 2){
            cout << "-1" << endl;
            return 0;
        }
    }
    if(abs(X[0]+Y[0]) % 2 == 0){
        is_even = true;
        for(int i = 0; i < N; i++){
            X[i]--;
        }
    }
    int m = 31;
    cout << m + (is_even? 1: 0) << endl;
    if(is_even){
        cout << "1 ";
    }
    for(int i = 0; i < m; i++){
        if(i){
            cout << " ";
        }
        cout << (1 << i);
    }cout << endl;

    for(int i = 0; i < N; i++){
        if(is_even){
            cout << 'R';
        }
        long long u = X[i] + Y[i];
        long long v = X[i] - Y[i];
        for(int j = 0; j < m; j++){
            bool plus_u = ((u + ((1<<m) - 1)) >> (j+1)) & 1;
            bool plus_v = ((v + ((1<<m) - 1)) >> (j+1)) & 1;
            if(plus_u && plus_v){
                cout << 'R';
            }else if(plus_u && !plus_v){
                cout <<'U';
            }else if(!plus_u && plus_v){
                cout <<'D';
            }else{
                cout << 'L';
            }
        }cout << endl;
    }
}
