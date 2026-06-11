#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
#include <map>
using namespace std;
int main(void){
    int n,M; cin >> n >> M;
    map<int, int> m;
    int i = 0;
    while (i < n) {
        int tmp;
        cin >> tmp;
        int j = 0;
        while (j < tmp) {
            int value;
            cin >> value;
            if (m.count(value)) {
                m[value] += 1;
            } else {
                m[value] = 1;
            }
            j++;
        }
        i++;
    }
    int count = 0;
    for (auto itr = m.begin(); itr != m.end(); itr++) {
        if (itr->second == n) count++;
    }
    cout << count << endl;
}