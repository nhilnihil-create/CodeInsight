#include <iostream>

#define endl '\n'
#define ll long long

using namespace std;

int main() {
    ll v[5], k;
    bool comunica = true;

    for(int i = 0; i < 5; i++) {
        cin >> v[i];
    }

    cin >> k;

    for(int i = 0; i < 5; i++) {

        for(int j = i + 1; j < 5; j++) {
            
            if(abs(v[i] - v[j]) > k) {
                comunica = false;
                break;
            }
        }
    }

    if(comunica) {
        cout << "Yay!" << endl;
    }

    else {
        cout << ":(" << endl;
    }

    return 0;
}