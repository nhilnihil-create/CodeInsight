#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = 0,b = 0,c = 0;

    for(int i = 0;i < 3;i++){
        switch(s.at(i)){
            case 'a':
            a++;
            break;
            case 'b':
            b++;
            break;
            case 'c':
            c++;
            break;
        }
    }

    if((a == 1)&&(b == 1)&&(c == 1)){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}