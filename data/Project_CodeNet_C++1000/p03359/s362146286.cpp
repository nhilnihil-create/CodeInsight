#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<string>
#include<map>
#include<queue>

using namespace std;

int main(void){

    int a, b;
    cin >> a >> b;

    cout << (a <= b ? a : a-1) << endl;

    return 0;
}