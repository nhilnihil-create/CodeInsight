#include <iostream>
#include <string>
using namespace std;

const int MAX_S = 8001;
bool dp_x[2][2*MAX_S];
bool dp_y[2][2*MAX_S];
int dx[MAX_S];
int dy[MAX_S];

int main() {
  string s;
  cin >> s;
  s.append(1, 'T');
  int x, y;
  cin >> x >> y;

  bool axis_change_flag = true;
  int lx = 0, ly = 0;
  for (unsigned long i = 0; i < s.length(); i++) {
    if (s[i] == 'F') {
      if (axis_change_flag) {
	dx[lx] += 1;
      }
      else {
	dy[ly] += 1;
      }
    }
    else {
      if (axis_change_flag) {
	lx++;
      }
      else {
	ly++;
      }
      axis_change_flag = !axis_change_flag;
    }
  }

  // cout << "x: ";
  // for (int i = 0; i < lx; i++) {
  //   cout << dx[i] << " ";
  // }
  // cout << endl;
  // cout << "y: ";
  // for (int i = 0; i < ly; i++) {
  //   cout << dy[i] << " ";
  // }
  // cout << endl;

  int rx = 0;
  dp_x[rx][MAX_S + dx[0]] = true;
  for (int i = 1; i < lx; i++) {
    int next_rx = (rx + 1) % 2;
    // cout << i << endl;
    for (int j = 0; j < 2*MAX_S; j++) {
      // cout << j << endl;
      int px = j - dx[i];
      int qx = j + dx[i];
      bool ux = (px >= 0 ? dp_x[rx][px] : false);
      bool vx = (qx < 2*MAX_S ? dp_x[rx][qx] : false);
      // if (ux || vx) {
      // 	cout << j << " ";
      // 	cout << qx << " " << ux << " ";
      // 	cout << px << " " << vx << endl;
      // }
      dp_x[next_rx][j] = ux || vx;
    }
    rx = next_rx;
  }

  int ry = 0;
  dp_y[ry][MAX_S + dy[0]] = true;
  dp_y[ry][MAX_S - dy[0]] = true;
  for (int i = 1; i < ly; i++) {
    int next_ry = (ry + 1) % 2;
    // cout << i << endl;
    for (int j = 0; j < 2*MAX_S; j++) {
      //cout << j << endl;
      int py = j - dy[i];
      int qy = j + dy[i];
      bool uy = (py >= 0 ? dp_y[ry][py] : false);
      bool vy = (qy < 2*MAX_S ? dp_y[ry][qy] : false);
      // if (uy || vy) {
      // 	cout << j << " ";
      // 	cout << qy << " " << uy << " ";
      // 	cout << py << " " << vy << endl;
      // }
      dp_y[next_ry][j] = uy || vy;
    }
    ry = next_ry;
  }

  cout << (dp_x[rx][x + MAX_S] && dp_y[ry][y + MAX_S]? "Yes" : "No") << endl;

}