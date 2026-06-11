#include <iostream>
using namespace std;

int main(){

int k,cont1=1 , cont2=1, soma1=0,soma=0;

cin >> k;

for (int i=1;i<=k;i++){
    if (cont2%2==1){soma++;}
    cont2++;
}

for (int i=1;i<=k;i++){
    if (cont1%2==0){soma1++;}
    cont1++;
}
cout << soma*soma1 << endl;
return 0;
}
