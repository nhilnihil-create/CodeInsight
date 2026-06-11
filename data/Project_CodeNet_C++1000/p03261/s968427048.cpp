#include <iostream>
using namespace std;

int main(){
    int N,i,j;
    string output = "Yes";
    cin>>N;
    string list[N];
    for (i=0;i<N;i++){
        cin>>list[i];
        if(i!=0){
            if(list[i][0] != list[i-1][list[i-1].size()-1]){
                output = "No";
            }
        }
        for (j=0;j<i;j++){
            if (list[i]==list[j]){
                output = "No";
            }
        }
    }
    cout<<output<<endl;
}