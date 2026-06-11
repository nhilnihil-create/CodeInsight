#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> times(5);
    vector<int> dist(5);
    int t = 0;

    int tmp = 0;
    int i = 0;
    while(cin >> tmp) {
        times[i] = tmp;

        int count = 0;

        while(!(tmp % 10 == 0)) {
            tmp ++;
            count ++;
        }

        dist[i] = count;

        i ++;

        if(i >= 5) {
            break;
        }
    }

    /*
    for(int i = 0; i < 5; i ++) {
        cout << dist[i] << endl;
    }
    */

    int loop = 0;

    while(1) { 
        loop ++;
        int min = dist[0];
        int id = 0;

        for(int i = 1; i < 5; i++) {
            if(min > dist[i]) {
                min = dist[i];
                id = i;
            }
        }

         t += times[id];

        if(loop == 5) {
            break;
        }

        t += dist[id];

        dist[id] = 10;


    }

    cout << t << endl;



}