#include <iostream>
using namespace std;

int main() {
    int N;

    cin >> N;

    string n_str = to_string(N);

    int keta_wa = 0;


    for (int i = 0; i < n_str.size(); i++) {
        int m = n_str[i] - 48;

        keta_wa += m;
    }

    if (N % keta_wa == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    

    return 0;

}



