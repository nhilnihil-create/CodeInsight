#include <iostream>
#include <bitset>
using namespace std;

int main() {

    string S;

    cin >> S ;

    string ans_str;

    // ビットの全組み合わせループ
    for (int tmp = 0; tmp < 1 << 3; tmp++) {

        //ビット表現(0000)
        bitset<3> s(tmp);
        //cout << s << "  -------"<<endl;

        long sum = S[0]-48;
        //cout << "sum: "<< sum << endl;

        string sum_str;
        ans_str = to_string(S[0]-48);

        for (long i = 0; i < S.size() - 1; i++) {
            sum_str = S[i+ 1];
            if (s.test(i)) {
                sum += stoll(sum_str.c_str());
                ans_str += "+" + sum_str;
            }else{
                sum -= stoll(sum_str.c_str());
                ans_str += "-" + sum_str;
            }
            //cout << "sum: "<< sum << endl;
        }
        if (sum == 7){
            //cout << S << endl;
            //
            ans_str += "=7"; 
            cout << ans_str << endl;
            return 0;

        }
    }
    //cout << ans_str << endl;

    return 0;

}