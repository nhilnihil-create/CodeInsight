#include <bits/stdc++.h>
using namespace std;
 
int main(){
   int N;
   cin>>N;
   vector<int> math(N);
   int sum=0;
   for(int i = 0;i<N;i++){
       cin >> math.at(i);
       sum += math.at(i);
   }
   
   
   int max=0;
   for (int j = 0; j<N;j++){
       if(max < math.at(j)){
           max = math.at(j);
       }
   }
    if(max*2<sum){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
   
}