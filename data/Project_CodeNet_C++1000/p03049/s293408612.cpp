#include <iostream>
using namespace std;
int main(){
    int N;
    cin >> N;
    string s;
    int a_b = 0, b_f = 0, b = 0, cnt = 0;
    bool f = 1;
    for(int i=0; i<N; i++){
        cin >> s;
        if(s[0]=='B' && s[s.size()-1]=='A'){
            b++;
        }else if(s[0]=='B'){
            b_f++;
        }else if(s[s.size()-1]=='A'){
            a_b++;
        }
        for(int j=0; j<s.size()-1; j++){
            if(s[j]=='A'&&s[j+1]=='B'){
                j++;
                cnt++;
            }
        }
    }
    cnt += b;
    if(b_f + a_b){
        cnt += min(a_b, b_f);
    }else if(b){
        cnt--;
    }
    cout << cnt << endl;
    return 0;
}