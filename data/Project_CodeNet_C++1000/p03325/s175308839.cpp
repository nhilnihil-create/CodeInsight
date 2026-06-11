#include<bits/stdc++.h>

using namespace std;

int main() {
int N;
cin>>N;
vector<int>a(N);
int x=0;
for(int i=0;i<N;i++){
   cin>>a[i];
}
for(int i=0;i<N;i++){
   
while(a[i]%2==0){
a[i]=a[i]/2;
x++;

}
}
cout<<x<<endl;
   return 0;
}




