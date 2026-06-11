#include <iostream>
using namespace std;

int main(){
	int A, B, C;
	cin >> A >> B >> C;
    int sound = B / A;
    if (sound > C) sound = C;
    cout << sound;
}