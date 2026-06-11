#include<bits/stdc++.h>
using namespace std;

int main(){
    //aが白(.)、bが黒(#)
    int a, b;
    cin >> a >> b;
    cout << ((min(a, b) + 23) / 25) * 4  + ((abs(a - b) + 50)/ 50) * 2 << " " << 100 << endl;
    if (b > a){
        int cnt = a - 1;
        while (cnt > 0){
            int tmp = 0;
            for (int i = 0; i < 25; i++){
                if (cnt == 0) break;
                cout << ".###";
                cnt--;
                tmp++;
            }
            for (int i = 0; i < 25 - tmp; i++) cout << "....";
            cout << endl;
            for (int i = 0; i < tmp; i++) cout << ".#.#";
            for (int i = 0; i < 25 - tmp; i++) cout << "....";
            cout << endl;
            for (int i = 0; i < tmp; i++) cout << ".###";
            for (int i = 0; i < 25 - tmp; i++) cout << "....";
            cout << endl;
            for (int i = 0; i < 100; i++) cout << ".";
            cout << endl;
        }
        int rmn = b - a + 1;
        int now = 1;
        while (rmn > 0){
            int tmp = 0;
            now ^= 1;
            for (int i = 0; i < 50; i++){
                if (rmn == 0) break;
                if (now) cout << "#.";
                else cout << ".#";
                rmn--;
                tmp++;
            }
            for (int i = 0; i < 50 - tmp; i++) cout << "..";
            cout << endl;
            for (int i = 0; i < 100; i++) cout << ".";
            cout << endl;
        }
    }
    else{
        int cnt = b - 1;
        while (cnt > 0){
            int tmp = 0;
            for (int i = 0; i < 25; i++){
                if (cnt == 0) break;
                cout << "#...";
                cnt--;
                tmp++;
            }
            for (int i = 0; i < 25 - tmp; i++) cout << "####";
            cout << endl;
            for (int i = 0; i < tmp; i++) cout << "#.#.";
            for (int i = 0; i < 25 - tmp; i++) cout << "####";
            cout << endl;
            for (int i = 0; i < tmp; i++) cout << "#...";
            for (int i = 0; i < 25 - tmp; i++) cout << "####";
            cout << endl;
            for (int i = 0; i < 100; i++) cout << "#";
            cout << endl;
        }
        int rmn = a - b + 1;
        int now = 1;
        while (rmn > 0){
            int tmp = 0;
            now ^= 1;
            for (int i = 0; i < 50; i++){
                if (rmn == 0) break;
                if (now) cout << "#.";
                else cout << ".#";
                rmn--;
                tmp++;
            }
            for (int i = 0; i < 50 - tmp; i++) cout << "##";
            cout << endl;
            for (int i = 0; i < 100; i++) cout << "#";
            cout << endl;
        }
    }
}


