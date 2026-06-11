#include<iostream>

using namespace std;

int main(){
    int flag(0);
    string str;
    cin >> str;
    if(str[0]=='A'){
        for(int i=2;i<str.size()-1;i++){
            if(str[i]=='C'){
                flag++;
            }
        }
        if(flag==1){
            if(islower(str[1])){
                for(int i=2;i<str.size()-1;i++){
                    if(isupper(str[i]) && str[i]!='C'){
                        cout << "WA";
                        exit(0);
                    }
                }
                if(islower(str[str.size()-1])){
                    cout << "AC";
                    exit(0);
                }
            }

        }
    }
    cout << "WA";
}