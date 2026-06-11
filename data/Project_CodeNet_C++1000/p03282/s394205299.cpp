#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    string s;
    int  k;
    cin>>s>>k;
    int count = 0;
//    long long int count = 0;
//    for (int i =0; i< s.length(); i++){
//        if (s[i]=='1'){
//            count++;
//            continue;
//        }
//        int temp = s[i]-'0';
//        count+=temp*5*pow(10, 15);
//        if (count>=k){
//            cout << s[i]<<endl;
//            break;
//        }
//
//    }
    for (int i =0; i< s.length(); i++){
        if (s[i]=='1'){
            count++;
            if (count ==k){
                cout <<'1';
                break;
            }
        }
        else{
            cout << s[i];
            break;
        }
    }
    
    
}