#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    double possibility=0;
    
    int counter=0;
    for(int j=1;j<n+1;j++){
    for(int i=j;i<k;i=i*2){
        counter++;
    }
    
        double n1=1;
        for(int y=0;y<counter;y++){
             n1=n1*2;
    }
        possibility = possibility + (1 / (n*n1));
        
        counter = 0;
    
    }
    
    
   
    cout << setprecision(11) << possibility << endl;
}