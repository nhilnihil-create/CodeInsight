#include <iostream>
#include <vector>
#include <memory>
using namespace std;

struct UnionFindPOL {
  vector<int> data;
  vector<int> position;

  UnionFindPOL(int size) : data(size, -1), position(size, 0) { 

  }

  bool unionSet(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }

  bool addDist(int l, int r, int d) {
      int rl = root(l);
      int rr = root(r);
      int posl = getAbsolutePosition(l);
      int posr = getAbsolutePosition(r);

      if(rl == rr) {
          if(posr - posl == d) {
              return true;
          } else {
              return false;
          }
      } else {
          if(data[rl] < data[rr]) {
            int offsetr = posl + d - posr;
            position[rr] = offsetr;
            data[rl] += data[rr];
            data[rr] = rl;
          } else {
            int offsetl = posr - d - posl;
            position[rl] = offsetl;
            data[rr] += data[rl];
            data[rl] = rr;
          }
          return true;
      }

  }

  int getAbsolutePosition(int x) {
      int pos = position[x];
      int p = data[x];
      while(p >= 0) {
          pos += position[p];
          p = data[p];
      }
      return pos;
  }

  bool findSet(int x, int y) {
    return root(x) == root(y);
  }

  int root(int x) {
    //return data[x] < 0 ? x : data[x] = root(data[x]);
    if(data[x] < 0) {
        return x;
    } else {
        //position[x] = getPosition(x);
        //return (data[x] = root(data[x]));
        return root(data[x]);
    }
  }

  int size(int x) {
    return -data[root(x)];
  }
};

int main() {
    int N, M;
    cin >> N >> M;
    UnionFindPOL ufpol(N+1);

    for(int i=0; i<M; i++) {
        int l, r, d;
        cin >> l >> r >> d;
        if(ufpol.addDist(l, r, d) == false) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}