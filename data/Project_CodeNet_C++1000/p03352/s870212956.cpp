#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int N;
cin >> N;
bool check = 0;
for(int i = N; i > 0; i--){
for(int j = 1; j < 35; j++)
if((i == j*j || i == j*j*j || i == j*j*j*j || i == j*j*j*j*j)&& check == 0){
    cout << i << endl;
    check = 1;
    break;
}

}


}

