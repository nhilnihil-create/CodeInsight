#include <iostream>
using namespace std;

int main(){
/*     int N = 4;
   string s = "RRBR";
*/

    int N;
    string s;
    cin >> N >> s;
    int cnt_R = 0;

    for (int i = 0; i < s.size(); i++){
        if (s[i] == 'R'){
            cnt_R++;
        }
    }
    int cnt_B = s.size() - cnt_R;

    if (cnt_R > cnt_B){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;

}