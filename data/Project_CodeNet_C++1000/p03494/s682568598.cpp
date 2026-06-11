#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int N;
    cin >> N;
    int count = 0;
    vector<int> A(N) ;
    for(int i=0;i<N;i++){
        cin >> A.at(i) ;
    }

    bool next;
    int num =0;

    for(int i=0;i>=0;i++){
        bool finished = false;
        bool next = false;
        for(int j=0;j<N;j++){
            if( (A.at(j)%2)==1 ){
             finished = true;
                break;
            }
            else if(((A.at(j)%2)==0)&&(j==N-1)){
                next = true;
            }
            
        }
        if(finished){
            break;
        }
        else{
            num = num + 1;
            if(next){
                for(int k=0;k<N;k++){
                    A.at(k) = (A.at(k))/2 ;
                }
            }
        }
    }
    cout << num << endl;

}