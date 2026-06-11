//while & if only
//completed

#include <bits/stdc++.h>
using namespace std;

int main() {

  int H, W, h = 0, w = 0, f = 0;
  string A, B, C;
  cin >> H >> W ;
  
  if ( H >= 2 && W >= 2) {
    cin >> A >> B;

    while (w < W) {
      if (A.at(w) == '.') A.at(w) = '0';
      w++;
    }

    w = 0;
    while (w < W) {
      if (B.at(w) == '.') B.at(w) = '0';
      w++;
    }

    if (A.at(0) != '#') {
      if (A.at(1) == '#') f++;
      if (B.at(0) == '#') f++;
      if (B.at(1) == '#') f++;
      A.at(0) += f;
    }

    w = 1;
    while (w < W - 1) {
      if (A.at(w) != '#') {
        f = 0;
        if (A.at(w - 1) == '#')  f++;
        if (A.at(w + 1) == '#')  f++;
        if (B.at(w - 1) == '#')  f++;
        if (B.at(w) == '#') f++;
        if (B.at(w + 1) == '#')  f++;
        A.at(w) += f;
      }
      w++;
    }

    if (A.at(W - 1) != '#') {
      f = 0;
      if (A.at(W - 2) == '#') f++;
      if (B.at(W - 2) == '#') f++;
      if (B.at(W - 1) == '#') f++;
      A.at(W - 1) += f;
    }

    cout << A << endl;


    while (h < H - 2) {
      cin >> C;

      w = 0;
      while (w < W) {
        if (C.at(w) == '.') C.at(w) = '0';
        w++;
      }

      if (B.at(0) != '#') {
        f = 0;
        if (A.at(0) == '#') f++;
        if (A.at(1) == '#') f++;
        if (B.at(1) == '#') f++;
        if (C.at(0) == '#') f++;
        if (C.at(1) == '#') f++;
        B.at(0) += f;
      }

      w = 1;
      while (w < W - 1) {
        if (B.at(w) != '#') {
          f = 0;
          if (A.at(w - 1) == '#')  f++;
          if (A.at(w) == '#')  f++;
          if (A.at(w + 1) == '#')  f++;
          if (B.at(w - 1) == '#')  f++;
          if (B.at(w + 1) == '#') f++;
          if (C.at(w - 1) == '#')  f++;
          if (C.at(w) == '#')  f++;
          if (C.at(w + 1) == '#')  f++;
          B.at(w) += f;
        }
        w++;
      }

      if (B.at(W - 1) != '#') {
        f = 0;
        if (A.at(W - 2) == '#') f++;
        if (A.at(W - 1) == '#') f++;
        if (B.at(W - 2) == '#') f++;
        if (C.at(W - 2) == '#') f++;
        if (C.at(W - 1) == '#') f++;
        B.at(W - 1) += f;
      }
      cout << B << endl;

      A = B, B = C;
      h++;
    }


    if (B.at(0) != '#') {
      f = 0;
      if (A.at(0) == '#') f++;
      if (A.at(1) == '#') f++;
      if (B.at(1) == '#') f++;
      B.at(0) += f;
    }

    w = 1;
    while (w < W - 1) {
      if (B.at(w) != '#') {
        f = 0;
        if (A.at(w - 1) == '#')  f++;
        if (A.at(w) == '#')  f++;
        if (A.at(w + 1) == '#')  f++;
        if (B.at(w - 1) == '#') f++;
        if (B.at(w + 1) == '#')  f++;
        B.at(w) += f;
      }
      w++;
    }

    if (B.at(W - 1) != '#') {
      f = 0;
      if (A.at(W - 2) == '#') f++;
      if (A.at(W - 1) == '#') f++;
      if (B.at(W - 2) == '#') f++;
      B.at(W - 1) += f;
    }

    cout << B << endl;
  }

  else if (H == 1 && W != 1) {
    cin >> A;

    while (w < W) {
      if (A.at(w) == '.') A.at(w) = '0';
      w++;
    }

    if (A.at(0) != '#') {
      if (A.at(1) == '#') f++;
      A.at(0) += f;
    }

    w = 1;
    while (w < W - 1) {
      if (A.at(w) != '#') {
        f = 0;
        if (A.at(w - 1) == '#')  f++;
        if (A.at(w + 1) == '#')  f++;
        A.at(w) += f;
      }
      w++;
    }

    if (A.at(W - 1) != '#') {
      f = 0;
      if (A.at(W - 2) == '#') f++;
      A.at(W - 1) += f;
    }

	cout << A;
  }

  else if (W == 1 && H != 1) {
    cin >> A >> B;

    if (A.at(0) == '.') A.at(0) = '0';

    if (B.at(0) == '.') B.at(0) = '0';

    if (A.at(0) != '#') {
      if (B.at(0) == '#') f++;
      A.at(0) += f++;
    }

    cout << A << endl;


    while (h < H - 2) {
      cin >> C;
      
      if (C.at(0) == '.') C = '0';

      if (B.at(0) != '#') {
        f = 0;
        if (A.at(0) == '#') f++;
        if (C.at(0) == '#') f++;
        B.at(0) += f;
      }
      
      cout << B << endl;
      A = B, B = C;
      h++;
    }


    if (B.at(0) != '#') {
      f = 0;
      if (A.at(0) == '#') f++;
      B.at(0) += f++;
    }

    cout << B << endl;
  }

  else if (H == 1 && W == 1) {
    cin >> A;
    if (A.at(0) == '.') A.at(0) = '0';
    cout << A << endl;
  }

}