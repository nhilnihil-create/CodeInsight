#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[2003];
    int s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    bitset<4194304> b(1);
    for(int i = 0; i < n; i++) b = (b | (b << a[i]));
    for(int j = (s + 1) / 2; j <= s; j++) if(b[j] == 1){
        cout << j << endl;
        return 0;
    }
}