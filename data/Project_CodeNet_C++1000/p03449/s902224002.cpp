#include <iostream>
#include <vector>
#include <map>
#include <bitset>

using namespace std;

int main(){
    int N;
    cin>>N;
    vector<vector<int>> A(2 ,vector<int>(N));

    for(int i=0;i<2;i++){
        for(int j=0;j<N;j++){
            cin>>A.at(i).at(j);
        }
    }
    int sum;
    int max_result = 0;
    for(int down=0;down<N;down++){
        sum=0;

        for(int i = 0;i<=down;i++){
            sum += A.at(0).at(i);
        }
        for(int i =down;i<N;i++){
            sum += A.at(1).at(i);
        }
        if(sum>max_result) max_result = sum;

    }
    cout<<max_result;


}






