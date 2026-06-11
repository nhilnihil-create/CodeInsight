#include <bits/stdc++.h>
using namespace std;

int main() {


int n;
//int *num=new int[4];
//char *s=new char[4];
cin >> n;
double *num=new double[n];
double sum=0;
for(int i=0;i<n;i++){
cin >> num[i];
sum+=num[i];
}
sum/=n;
//sort(num,num+n);

double mi=101;
for(int i=0;i<n;i++){
mi=min(abs(num[i]-sum),mi);
}

for(int i=0;i<n;i++){
if(abs(num[i]-sum)==mi){
cout << i << endl;
break;
}

}


//cout << mi << endl;



}
