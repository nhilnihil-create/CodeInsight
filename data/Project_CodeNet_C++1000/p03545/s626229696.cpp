#include<iostream>
#include<bitset>
#include<vector>
#include<string>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> a(4);
    for (int i = 0; i < 4;i++){
       a.at(i)=s.at(i)-'0'; 
    }
    bool ok = false;
    for (int bit = 0; bit < (1 << 3); bit++){
        bitset<3> tmp(bit);
        int ans = a.at(0);
        //cout << tmp << endl;
        for (int i = 2; i>=0;i--){
           
            if(tmp.test(i)){
                ans+=a.at(3-i);
            }else{
                ans-= a.at(3-i);
            }

            if(ans==7){
                ok = true;
                cout << a.at(0);
                for (int i = 2; i >= 0;i--){
                    if(tmp.test(i)){
                        cout << '+';
                    }else{
                        cout << '-';
                    }
                    cout << a.at(3 - i);
                }
                cout << "=7" << endl;

                return 0;
            }
        }
    }
    


    return 0;
}