#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, Q;
    string S;

    cin >> N >> Q;

    vector <int> l(Q);
    vector <int> r(Q);
    vector <int> t(N+1);
    //vector <int> result(Q);

    cin >> S;

    for(int i = 0; i < Q; i++) {
        cin >> l[i] >> r[i];
    }

    //cout << S.substr(0, 2) << endl;

    
    t[0] = 0;
    for(int i = 0; i < N; i ++) {
        int tmp = 0;

        if(S.substr(i, 2) == "AC") {
            tmp ++;
        } 

        t[i+1] = t[i] + tmp;
    }


    /*
    for(int i = 0; i < N; i++) {
        cout << t[i] << endl;
    }
    */

    for(int i = 0;i < Q; i++) {
        cout << t[r[i]-1] - t[l[i]-1] << endl;
    }
    
}