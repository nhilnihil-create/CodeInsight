#include<iostream>
using ll = long long;
using namespace std;

int main()
{
    ll a, b;
    cin >> a >> b;
    if(a == 0){
        switch(b % 4){
            case 0:
                cout << b << endl;
                break;
            case 1:
                cout << 1 << endl;
                break;
            case 2:
                cout << b+1 << endl;
                break;
            case 3:
                cout << 0 << endl;
                break;
        }
    } else{
        switch(b % 4){
            case 0:
                switch((a-1) % 4){
                    case 0:
                        cout << ((a-1) ^ b) <<  endl;
                        break;
                    case 1:
                        cout << (1 ^ b) << endl;
                        break;
                    case 2:
                        cout << (a ^ b) << endl;
                        break;
                    case 3:
                        cout << b << endl;
                        break;
                }
                break;
            case 1:
                switch((a-1) % 4){
                    case 0:
                        cout << ((a-1) ^ 1) <<  endl;
                        break;
                    case 1:
                        cout << (1 ^ 1) << endl;
                        break;
                    case 2:
                        cout << (a ^ 1) << endl;
                        break;
                    case 3:
                        cout << 1 << endl;
                        break;
                }
                break;
            case 2:
                switch((a-1) % 4){
                    case 0:
                        cout << ((a-1) ^ (b+1)) <<  endl;
                        break;
                    case 1:
                        cout << (1 ^ (b+1)) << endl;
                        break;
                    case 2:
                        cout << (a ^ (b+1)) << endl;
                        break;
                    case 3:
                        cout << b+1 << endl;
                        break;
                }
                break;
            case 3:
                switch((a-1) % 4){
                    case 0:
                        cout << a-1 <<  endl;
                        break;
                    case 1:
                        cout << 1 << endl;
                        break;
                    case 2:
                        cout << a << endl;
                        break;
                    case 3:
                        cout << 0 << endl;
                        break;
                }
                break;
        }
    }
    return 0;
}
   