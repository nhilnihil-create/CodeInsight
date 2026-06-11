#include <iostream>

using namespace std;

int main()
{
    int n , k;
    string s;
    cin >> n >> k >> s;
    char a = s[k - 1];
    switch ((int)a){
        case 65:
            a = 'a';
            break;
        case 66:
            a = 'b';
            break;
        case 67:
            a = 'c';
            break;
    }
    for (int i = 0 ; i < n ; i++){
        if (i == k - 1){
            cout << a;
        }else{
            cout << s[i];
        }
    }
    return 0;
}
