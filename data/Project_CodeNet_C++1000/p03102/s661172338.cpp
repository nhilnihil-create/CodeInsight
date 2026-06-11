#include<iostream>
#include<vector>
#include <stdio.h>
using namespace std;

int N, M, C;
vector<vector<int> > A(20, vector<int>(20));
int B[20];
int correct = 0;

int main(){
    cin >> N >> M >> C;
    for (int i = 0; i < M; i++) cin >> B[i];
    for (int i = 0; i < N; i++)
    {
        // printf("%d\n", i);
        int tmp = 0;
        for (int j = 0; j < M; j++)
        {
            cin >> A.at(i).at(j);
            tmp += A.at(i).at(j) * B[j];
            /* code */
        }
        if(tmp + C > 0){
            correct++;
        }    
    }
    cout << correct << endl;
    
    
}