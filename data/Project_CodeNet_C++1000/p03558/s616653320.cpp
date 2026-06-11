#include <iostream>
#include <vector>
#include <map>
 
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> dist(N, -1);
  int addedCount = 0;
  vector<bool> added(N);
  vector<int> list;
  int temp = 1;
  while (!added[temp]) {
    added[temp] = true;
    addedCount += 1;
    dist[temp] = 0;
    list.push_back(temp);
    temp = (temp * 10) % N;
  }

  int tempDist = 0;
  while (addedCount < N) {
    tempDist += 1;
    vector<int> tempList;
    for (int i = 0; i < list.size(); i++) {
      temp = (list[i] + 1) % N;
      while (!added[temp]) {
        added[temp] = true;
        addedCount += 1;
        dist[temp] = tempDist;
        tempList.push_back(temp);
        temp = (temp * 10) % N;
      }
    }

    list = tempList;
  }

  cout << dist[0] + 1 << endl;

  return 0;
}