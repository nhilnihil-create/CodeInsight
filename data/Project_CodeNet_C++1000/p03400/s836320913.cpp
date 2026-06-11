#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int N;
cin >> N;
int D, X;
cin >> D >> X;
int choco[110];
for(int i = 0; i < N; i++){
cin >> choco[i];
}

for(int i = 0; i < N; i++){
    int niti = 1;
while(D >= niti){
niti += choco[i];
X++;
}


}
cout << X << endl;

}