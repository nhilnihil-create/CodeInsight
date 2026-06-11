#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
    string N;
    cin >> N;
    int a = stoi(N);
    int count = 0;
    for(int i = 0; i < N.size(); i++){
        char b = N[i];
        int c = int(b - '0');
        count+=c;
    }
    if(a % count == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
