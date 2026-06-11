#include<iostream>
#include<string>
using namespace std;
int main() {
    int A, B;
    cin >> A >> B;
    int a[10];
    int ta, tb;
    int c = 0;

    for(int i = A; i <= B; i++){
        ta = i;
        for(int j = 0; j < 5; j++){
            a[j] = ta % 10;
            ta /= 10;
        }
        if(a[0]==a[4] && a[1] == a[3])
            c++;    
    }
    cout << c << endl;
    return 0;
}