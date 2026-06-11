#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;



int main() {
int dish[5];
for(int i = 0; i < 5; i++){
    cin >> dish[i];
}
int time = 0;
int mi = 9;
int last = 0;
for(int i = 0; i < 5; i++){
  int hika = dish[i] % 10;
  if(hika < mi && hika != 0){
last = i;
mi = hika;
  }
}

for(int i = 0; i < 5; i++){
if(dish[i] % 10 == 0 || i == last)time += dish[i];
else time += ((dish[i]/10)+1)*10;

}
cout << time << endl;

}
