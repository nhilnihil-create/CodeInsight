#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

#define MAX_N (100)
#define MAX_T (200)

using namespace std;

int main(int argc, char *argv[]) {
  // read inputs
  int N, ts[MAX_N], vs[MAX_N];
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("%d", &ts[i]);
  }
  for (int i = 0; i < N; i++) {
    scanf("%d", &vs[i]);
  }

  // calculate accumulated time
  int taccs[MAX_N + 1];
  taccs[0] = 0;
  for (int i = 0; i < N; i++) {
    taccs[i + 1] = taccs[i] + ts[i];
  }

  // calculate the maximum velocity for each time step (0.5s)
  double max_velocities[2 * MAX_N * MAX_T + 1];
  double limit_velocities[2 * MAX_N * MAX_T + 1];
  int segment = N - 1;
  max_velocities[2 * taccs[N]] = 0;
  limit_velocities[2 * taccs[N]] = vs[segment];
  for (int t = 2 * taccs[N] - 1; t >= 0; t--) {
    double limit_velocity;
    if (segment > 0 && t == 2 * taccs[segment]) {
      limit_velocity = min(vs[segment], vs[segment - 1]);
      segment--;
    } else {
      limit_velocity = vs[segment];
    }
    max_velocities[t] = min(max_velocities[t + 1] + 0.5, limit_velocity);
    limit_velocities[t] = limit_velocity;
  }

  // determine the velocity for each time step
  double velocities[MAX_N * MAX_T + 1];
  velocities[0] = 0;
  for (int t = 1; t <= 2 * taccs[N]; t++) {
    velocities[t] = min(velocities[t - 1] + 0.5, max_velocities[t]);
  }

  // for (int t = 0; t <= taccs[N]; t++) {
  //   printf("t = %3lf, v = %5lf, max_v = %5lf, limit_v = %lf\n", t / 2.0,
  //          velocities[t], max_velocities[t], limit_velocities[t]);
  // }

  // calculate the distance traveled
  double d = 0;
  for (int t = 1; t <= 2 * taccs[N]; t++) {
    d += velocities[t] + velocities[t - 1];
  }
  d *= 0.25;
  printf("%.5lf\n", d);

  return 0;
}
