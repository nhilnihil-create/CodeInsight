#include <iostream>
#include <functional>
using namespace std;

int main() {
    int N;
    cin >> N;

    int* P = new int[N];
    int* Q = new int[N];
    for(int i=0; i<N; i++)
    {
        cin >> P[i];
        Q[P[i]-1] = i;
    }

    int max_order = 1;
    int order = 1;
    for(int i=1; i<N; i++)
    {
        if(Q[i-1] < Q[i]) {
            order++;
            if (max_order < order) max_order = order;
        } else {
            order = 1;
        }
        
    }


    cout << N - max_order;
}