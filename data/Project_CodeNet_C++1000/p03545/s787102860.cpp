#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> t(4);
    for (int i = 0; i < 4; i++){
        t.at(i) = n / pow(10, (3-i));
        n = n % (int)pow(10, (3-i));
    }

    int t7;

    for (int i = 0; i < 8; i++){

        int sumt = t.at(0);

        for (int j = 0; j < 3; j++){
            if ((i % (int)pow(2, (3 - j))) / (int)pow(2, (2 - j)) == 1){
                sumt += t.at(j + 1);
            }else{
                sumt -= t.at(j + 1);
            }
        }

        if (sumt == 7){
            t7 = i;
            break;
        }
    }

    cout << t.at(0);
    for (int i = 0; i < 3; i++){
        if ((t7 % (int)pow(2, (3 - i))) / (int)pow(2, (2 - i)) == 1){
            cout << "+" << t.at(i + 1); 
        }else{
            cout << "-" << t.at(i + 1);
        }
    }
    cout << "=7" << endl;
    //cout << t.at(0) << t.at(1) << t.at(2) << t.at(3) << endl;
}