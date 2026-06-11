#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N,Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    int lr[Q][2];
    for(int i =0; i < Q; i++){
        cin >> lr[i][0] >> lr[i][1];
    }
    vector<int> v(N+10);
    for(int i = 2; i < N+1; i++){
        if(s.at(i-1) == 'C' && s.at(i - 2)=='A'){
            v[i] = v[i-1] + 1;
        }
        else{
            v[i] = v[i-1];
        }
    }
    for(int i =0; i < Q; i++){
        int l,r;
        l = lr[i][0];
        r = lr[i][1];
        if(v[l] == v[l-1]){
            cout << v[r] - v[l -1] << endl;
        }
        else{
            cout << v[r] - v[l -1] -1 << endl;
        }
    }
}