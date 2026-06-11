#include<iostream>
#include<map>

using namespace std;

int main(){
map<char,int> count;
int n;
cin>>n;
char value;
for(int i=0;i<n;i++){
cin>>value;
count[value]+=1;
}
if(count['R']>count['B']) cout<<"Yes";
else cout<<"No";

    return 0;

}