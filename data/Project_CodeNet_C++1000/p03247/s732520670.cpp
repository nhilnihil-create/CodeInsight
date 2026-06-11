    #include <bits/stdc++.h>
     
    using namespace std;
     
    // https://atcoder.jp/contests/arc103/tasks/arc103_b
     
    struct Point {
      int x;
      int y;
      int u;
      int v;
    };
     
    void resolve(const vector<Point> &points, int mod2, size_t n) {
      vector<int> ads;
      for(int i = 30; i >= 0; i--) ads.push_back(1 << i);
      if(points[0].u % 2 == 0) ads.push_back(1);
      int M = ads.size();
      cout << M << endl;
      for(size_t i = 0; i < M; i++) cout << ads[i] << " \n"[i == M - 1];
     
      for(size_t i = 0; i < n; i++) {
          int xpy = points[i].u, xmy = points[i].v;
          for(auto&& ad : ads) {
              if(xpy >= 0){
                  if(xmy >= 0){
                      cout << "R";
                      xpy -= ad;
                      xmy -= ad;
                  }else{
                      cout << "U";
                      xpy -= ad;
                      xmy += ad;
                  }
              } else {
                  if(xmy >= 0) {
                      cout << "D";
                      xpy += ad;
                      xmy -= ad;
                  } else {
                      cout << "L";
                      xpy += ad;
                      xmy += ad;
                  }
              }
          }
          cout << endl;
      }
    }
     
    int main() {
      size_t n;
      cin >> n;
     
     
      vector<Point> points(n);
      int mod2 = 0;
      int m = 0;
      for (size_t i = 0; i < n; i++) {
        Point &tPoint = points[i];
        cin >> tPoint.x >> tPoint.y;
        tPoint.u = (tPoint.x + tPoint.y);
        tPoint.v = (tPoint.x - tPoint.y);
     
        int tMod2 = abs((tPoint.u) % 2);
        if (i == 0) {
          mod2 = tMod2;
        } else if (mod2 != tMod2) {
          m = -1;
          break;
        }
      }
     
      if (m == -1) {
        cout << -1 << "\n";
      } else {
        resolve(points, mod2, n);
      }
     
      return 0;
    }