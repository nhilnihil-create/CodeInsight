#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int A, B;

    cin >> A >> B;

    int cnt = 0;

    for (int i = A; i <= B; i++) {

        //int target = i;
        string target_s = to_string(i);
        //cout << "target_s: " << target_s <<  endl;

        int keta = target_s.size();
        int keta_han = keta / 2;

        //cout << "keta    : " << keta <<  endl;
        //cout << "keta_han: " << keta_han <<  endl;


        bool ok = true;

        for (int j = 0; j < keta_han; j++) {
            //cout << "t1: " << target_s[j] <<  endl;
            //cout << "t2: " << target_s[keta - j - 1]<<  endl;
            if(target_s[j] == target_s[keta - j - 1]){
            }
            else{
                ok = false;
            }

        }

        if(ok){
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;

}



